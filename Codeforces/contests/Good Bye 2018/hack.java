import java.util.*;
import java.io.*;

public class hack{
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        TreeSet<Integer> s1 = new TreeSet<Integer>();
        TreeSet<Integer> s2 = new TreeSet<Integer>();
        TreeSet<Integer> y1 = new TreeSet<Integer>();
        TreeSet<Integer> y2 = new TreeSet<Integer>();
        for(int i=0;i<n;++i){
            s1.add(sc.nextInt());
            y1.add(sc.nextInt());
        }
        for(int i=0;i<n;++i){
            s2.add(sc.nextInt());
            y2.add(sc.nextInt());
        }
        HashMap<Integer,Integer> h = new HashMap<Integer,Integer>();
        int nb;
        boolean ok=true;
        for(int i:s1){
            for(int j:s2){
                if(h.containsKey(i+j)){
                    nb=h.get(i+j);
                    nb++;
                    h.put(i+j,nb);
                }
                else{
                    if(ok){
                        h.put(i+j,1);
                    }
                }
            }
            ok=false;
        }
        for(Map.Entry<Integer,Integer> e:h.entrySet()){
            int key=e.getKey();
            int value=e.getValue();
            if(value==s1.size()) System.out.print(key+" ");
        }
        h.clear();
        ok=true;
        for(int i:y1){
            for(int j:y2){
                if(h.containsKey(i+j)){
                    nb=h.get(i+j);
                    nb++;
                    h.put(i+j,nb);
                }
                else{
                    if(ok){
                        h.put(i+j,1);
                    }
                }
            }
            ok=false;
        }
        for(Map.Entry<Integer,Integer> e:h.entrySet()){
            int key=e.getKey();
            int value=e.getValue();
            if(value==s1.size()) System.out.print(key+" ");
        }
    }
}
