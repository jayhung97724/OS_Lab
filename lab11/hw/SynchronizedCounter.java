public class SynchronizedCounter implements Runnable{
        public int count = 0,key = 1;
        public synchronized void run(){
                if(key % 2 == 1)
                {
                        key++;
                        for(int i =0;i<25000000;i++){
                                count++;
                        }
                }else
                {
                        key++;
                        for(int i =0;i<25000000;i++){
                                count--;
                        }
                }
        }
        public int getvalue(){
                return count;
        }

        public static void main(String[] args) {
                SynchronizedCounter Syc = new SynchronizedCounter();
                Thread thread0 = new Thread(Syc);
                Thread thread1 = new Thread(Syc);
                Thread thread2 = new Thread(Syc);
                Thread thread3 = new Thread(Syc);

                thread0.start();
                thread1.start();
                thread2.start();
                thread3.start();

                try{
                        thread0.join();
                        thread1.join();
                        thread2.join();
                        thread3.join();
                }catch(InterruptedException e){}

                System.out.printf("Count is: %d\n",Syc.getvalue());
        }
}
