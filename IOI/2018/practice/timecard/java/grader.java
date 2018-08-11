import java.io.EOFException;
import java.io.IOException;

public class grader {
	public static void main(String[] args) throws IOException {
		int n = readInt();
		new record().init(n);
		StringBuilder builder = new StringBuilder();
		for(int i = 0 ; i < n ; i ++){
			String s = readString();
			String t = new record().convert(s);
			builder.append(t+"\n");
		}
		System.out.print(new String(builder));
	}
	private static int readInt() throws IOException{
		int x = 0, c;
		for (; ; ) {
			c = System.in.read();
			if ('0' <= c && c <= '9') break;
			if (c == -1) throw new EOFException();
			if (c == '-') return -readInt();
		}
		for (; ; ) {
			x = x * 10 + (c - '0');
			c = System.in.read();
			if (!('0' <= c && c <= '9')) return x;
		}
	}
	private static String readString() throws IOException{
		char str[] = new char[22];
		int c,k=0;
		for(;;){
			c = System.in.read();
			if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')){
				str[k] = (char)c;
				k ++;
			}
			else break;
		}
		return new String(str,0,k-1);
	}
}
