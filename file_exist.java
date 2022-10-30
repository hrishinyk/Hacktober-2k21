import java.io.*;
public class file_exist{
public static void main(String args[]){
File obj =new File("file.txt");
if(obj.exists()){
	System.out.println("File name: "+obj.getName());
	System.out.println("Absolute path: "+obj.getAbsolutePath());
	System.out.println("Writeable: "+obj.canWrite());
	System.out.println("Readable: "+obj.canRead());
	System.out.println("File size in bytes: "+obj.length());
} 
else{
	System.out.println("File doesn't exist"); }
}  
}
