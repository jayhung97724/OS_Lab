public class ex1 implements Runnable{
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
                ex1 Syc = new ex1();
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

                System.out.printf("(%d)\n",Syc.getvalue());
        }
}
