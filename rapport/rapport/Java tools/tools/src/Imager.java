import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Arrays;

import javax.imageio.ImageIO;




public class Imager {
	static BufferedImage img = null;

	static int[] ansiColors = { 
		color( 0, 0, 0 ),
		color( 187, 0, 0 ),
		color( 0, 187, 0 ),
		color( 187, 187, 0 ),
		color( 0, 0, 187 ),
		color( 187, 0, 187 ),
		color( 0, 187, 187 ),
		color( 187, 187, 187 ),
		color( 85, 85, 85 ),
		color( 255, 85, 85 ),
		color( 85, 255, 85 ),
		color( 255, 255, 85 ),
		color( 85, 85, 255 ),
		color( 255, 85, 255 ),
		color( 85, 255, 255 ),
		color( 255, 255, 255 )
	};

	static String charString = "";
	static String colorString = "";

	static double[] charColor0 = { // %foreground color
		 0 , //only bg
		 0.25 , //25% shade
		 0.5  //50% shade
	};
	static int[] charColor1 = { //char}
		 ' ', //only bg
		 0xB0, //25% shade
		 0xB1 //50% shade
	};

	static int[][] colorChar = {}; //{mixcolor, foreground, background, char}


	public static void main( String[] args ) throws IOException {
		//makeCharColor(); //generate map of characters an the % of foreground they provide. Looks a bit dodgy without dithering....

		makeColorMap();

		img = ImageIO.read(new File("splash.png"));

		for( int i = 0; i < img.getHeight(); i++ ) {
			for( int j = 0; j < img.getWidth(); j++ ) {
				int color = img.getRGB( j, i );
				color = closestColor( color );

				charString += "0x" + Integer.toHexString( colorChar[color][3] ) + ", ";
				colorString += "0x" + Integer.toHexString( colorChar[color][1]<<4 | colorChar[color][2] ) + ", ";
			}
			charString += "\n";
			colorString += "\n";
		}

		String fin = "{";
		fin += charString;
		fin += "\n";
		fin += colorString;
		fin = fin.substring( 0, fin.length()-3 );
		fin += " };";

		System.out.println( fin );

	}

	public static void makeCharColor() throws IOException {
		BufferedImage img = ImageIO.read(new File("charset.png"));
		int charW = 9;
		int charH = 14;
		int charsX = 32;
		int charsY = 8;
		int len = 0;
		
		
		charColor0 = new double[charsX * ( charsY - 1 )];
		charColor1 = new int[charsX * ( charsY - 1)];
		
		for( int i = 1; i < charsY; i++ ) {
			for( int j = 0; j < charsX; j++ ) {
				// for all characters
				double average = 0;
				for( int ii = 0; ii < charH; ii++ ) {
					for( int jj = 0; jj < charW; jj++ ) {
						// for every pixel
						average += img.getRGB( j * charW + jj, i * charH + ii ) & 0xFF;
					}
				}
				average /= charW * charH;
				charColor0[len] = average/255;
				charColor1[len] = i * charsX + j;
				len++;
			}
		}
		System.out.println( Arrays.toString(charColor0));
		System.out.println( Arrays.toString(charColor1));




	}

	public static double colorDistance( int color1, int color2 ) {
		int red1 = color1>>16 & 0xFF;
				int green1 = color1>>8 & 0xFF;
			int	blue1 = color1 & 0xFF;
			int	red2 = color2>>16 & 0xFF;
			int green2 = color2>>8 & 0xFF;
			int	blue2 = color2 & 0xFF;
			red1 = red1 - red2;
			green1 = green1 - green2;
			blue1 = blue1 - blue2;

			return ( ( (double)red1 ) * ( (double)red1 )
					+ ( (double)green1 ) * ( (double)green1 )
					+ ( (double)blue1 ) * ( (double)blue1 )
					); //dist^2
	}


	public static int color( int r, int g, int b ) {
		return ( (r<<16) | (g<<8) | (b) );
	}

	public static int mixColors( int color1, int color2, double amC1 ) {
		int red1 = color1>>16 & 0xFF;
		int green1 = color1>>8 & 0xFF;
		int	blue1 = color1 & 0xFF;
		int	red2 = color2>>16 & 0xFF;
		int green2 = color2>>8 & 0xFF;
		int	blue2 = color2 & 0xFF;

		red1 = (int)(red1*amC1 + red2*(1-amC1));
		green1 = (int)(green1*amC1 + green2*(1-amC1));
		blue1 = (int)(blue1*amC1 + blue2*(1-amC1));

		return ( (red1<<16) | (green1<<8) | (blue1) );
	}

	public static void makeColorMap() {
		int len = 0;
		for( int ii = 0; ii < ansiColors.length; ii++ ){
			for( int i = ii; i < ansiColors.length; i++ ){
				for( int j = 0; j < charColor0.length; j++ ){
					len++;
				}
			}
		}
		//System.out.println( len );
		colorChar = new int[len][4];
		len = 0;
		for( int ii = 0; ii < ansiColors.length; ii++ ){
			for( int i = ii; i < ansiColors.length; i++ ){
				for( int j = 0; j < charColor0.length; j++ ){
					colorChar[len][3] = charColor1[j]; //set character
					colorChar[len][1] = i;
					colorChar[len][2] = ii;
					colorChar[len][0] = mixColors( ansiColors[i], ansiColors[ii], charColor0[j] );
					len++;
				}
			}
		}
		//System.out.println( Arrays.deepToString( colorChar ) );
	}

	public static int closestColor( int color ) {
		int tmpColor = colorChar[0][0];
		double dist = colorDistance( color, tmpColor );
		int id = 0;
		for (int i = 0; i < colorChar.length; i++ ) {
			if ( colorDistance( color, colorChar[i][0] ) < dist ) {
				dist = colorDistance( color, colorChar[i][0] );
				id = i;
			}
		}
		return id; //id in colorchar with closest color
	}
}

