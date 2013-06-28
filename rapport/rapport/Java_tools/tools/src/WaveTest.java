import java.io.*;

public class WaveTest {
	public final static int BUFFERSIZE = 1;
	public final static int NPEAK = 10;
	public final static int NAVER = 512;
	public final static int OCHN = 13;

	public static void main(String[] args){
		try
		{
			// Open the wav file specified as the first argument
			WavFile inputFile = WavFile.openWavFile(new File("tick.wav"));			

			// Display information about the wav file
			inputFile.display();

			//Create outputfile
			long farmesTotal = inputFile.getNumFrames();
			long sampleRate = inputFile.getSampleRate();
			
			// Create a buffer of 100 frames
			int[] bufferIn = new int[BUFFERSIZE];
			
			int framesRead;

					
			String out = "static const uint8_t tickTable[] = { ";
			String len = "static const int32_t tickLength = ";
			int lenI = 0;
			do
			{
				// Read frames into buffer
				framesRead = inputFile.readFrames(bufferIn, BUFFERSIZE);

				// Loop through frames and look for minimum and maximum value
				for (int s=0 ; s<framesRead ; s++) {
					int sig = bufferIn[s];
					out += "0x" + Integer.toHexString( ( ( sig + 0x8000 ) >> 8 ) & 0xff ) + ", ";
					lenI++;
					
							//write back
				}


			}
			while (framesRead != 0);

			out = out.substring( 0, out.length() - 2 ) + " };";
			len += lenI + ";";
			
			System.out.println( out );
			System.out.println( len );
			// Close the wavFile
			inputFile.close();

		}
		catch (Exception e)
		{
			System.err.println(e);
		}
	}
}