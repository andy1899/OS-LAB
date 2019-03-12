import java.util.*;
    class Producer implements Runnable{
        ArrayList<Integer> b=null;
        final int limit=10;
        int i=0;
        Producer(ArrayList<Integer> buffer){
            b=buffer;
        }
        public void run(){
            while(true){
                try{
                    i++;
                    produce(i);
                }
                catch(Exception e){
                    System.out.println(e);
                }
            }
        }
    public void produce(int i) throws InterruptedException{
        synchronized(b){
            while(b.size()==limit){
                System.out.println("Producer is waiting for consumer");
                b.wait();
            }
        }
        synchronized(b){
            b.add(i);
            System.out.println("Producer is producing item="+i);
            Thread.sleep(100);
            b.notify();
        }
    }
}       

    class Consumer implements Runnable{
        ArrayList<Integer> b=null;
        int i=0;
        Consumer(ArrayList<Integer> buffer){
            b=buffer;
        }
        public void run(){
            while(true){
                try{
                    consume(i);
                }
                catch(Exception e){
                    System.out.println(e);
                }
            }
        }
    public void consume(int i) throws InterruptedException{
        synchronized(b){
            while(b.isEmpty()){
                System.out.println("Consumer is waiting for Producer");
                b.wait();
            }
        }
        synchronized(b){
            b.remove(i);
            System.out.println("Consumer is consuming item="+i);
            Thread.sleep(100);
            b.notify();
        }
    }
}

public class ProducerConsumer {
    public static void main(String[] args) {
        ArrayList<Integer> buffer=new ArrayList<Integer>();
            Thread t1=new Thread(new Producer(buffer));
            Thread t2=new Thread(new Consumer(buffer));
            t1.start();
            t2.start();
        }
    }
