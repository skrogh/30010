import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;




public class Transcriber {
	public static final int OFF = 127;
	public static int prev = OFF;
	public static int length = 0;
	static String noteStr = "static const int32_t popBass1N[] = {";
	static String transStr = "static const int32_t popBass1T[] = {";

	public static void main( String[] args ) throws FileNotFoundException {




		Scanner lineReader = new Scanner( new File( "popBass1.txt" ) );
		String line = "";
		while( lineReader.hasNextLine() ) {
			line = lineReader.nextLine();
			if ( line.length() == 0 ) {
				output( prev, false );
			} else {

				switch ( line.charAt( 0 ) ) {
				case '-':
					output( OFF, false );
					break;
				case 'A':
				case 'B':
				case 'C':
				case 'D':
				case 'E':
				case 'F':
				case 'G':
				case 'a':
				case 'b':
				case 'c':
				case 'd':
				case 'e':
				case 'f':
				case 'g':
					int note = note( line );
					output( note, true );	
					break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					int note1 = line.charAt(0) - '0';
					output( note1, true );	
					break;
				}

			}

		}

		lineReader.close();
		noteStr = noteStr.substring( 0 , noteStr.length() - 2 );
		transStr = transStr.substring( 0 , transStr.length() - 2 );

		noteStr += " };";
		transStr += " };";

		System.out.println( noteStr );
		System.out.println( transStr );

	}

	public static void output( int out, boolean newNote ) {
		noteStr += "0x" + Integer.toHexString( out ) + ", ";
		transStr += "0x" + Integer.toHexString( ( ( out!=OFF )?2:0 ) + ( newNote?1:0 ) ) + ", ";
		length++;
		prev = out;
	}

	public static int note( String line ) {
		int note=0;

		switch( line.toLowerCase().charAt( 0 ) ) {
		case 'a':
			note = 0;
			break;
		case 'b':
			note = 2;
			break;
		case 'c':
			note = 3;
			break;
		case 'd':
			note = 5;
			break;
		case 'e':
			note = 7;
			break;
		case 'f':
			note = 8;
			break;
		case 'g':
			note = 10;
			break;
		}


		if ( line.charAt( 1 ) == '#' )
			note++;
		if ( line.charAt( 1 ) == 'b' )
			note--;
		note += ( line.charAt( 2 ) - '0' )*12;

		//transpose
		note -= 12;

		return note;
	}


}
