import java.util.concurrent.locks.*;

public class ProducerNConsumer implements Runnable{
        private Lock lock = new ReentrantLock();
        private Condition threadCond = lock.newCondition();
        public int  key = 1;
        //-1 ProducerNConsumer is empty
        private int product = 0;
        public void run(){
                if(key % 2 == 1)
                {
                        key++;
                        for(int i = 0; i < 50;i++){
                                Produce();
                        }
                }else
                {
                        key++;
                        for(int i = 0;i < 50;i++){
                        Consume();
                        }
                }
        }

        //call by producer
        public void Produce(){
                lock.lock();
                try{
                        while(this.product >=10){
                                try{
                                        //ProducerNConsumer is full and producer wait
                                        System.out.printf("Product stack is full\n");
                                        threadCond.await();
                                }catch(InterruptedException e){
                                        e.printStackTrace();
                                }
                        }
                        this.product++;

                        System.out.printf("Produce: %d\n", this.product);

                        // signal consumer
                        threadCond.signal();
                }
                finally {
                        lock.unlock();
                }
                //can be preemptive
                for(int i=0;i <100000;i++){}
        }

        public void Consume(){
            lock.lock();
            try{
                    while(this.product == -1){
                        try{
                                //no product
                                System.out.printf("Product stack is empty\n");
                                threadCond.await();
                        }catch(InterruptedException e){
                                e.printStackTrace();
                        }
                    }
                    System.out.printf("Consume: %d\n", this.product);
                    this.product--;

                    //signal producer
                    threadCond.signal();
            }
            finally{
                    lock.unlock();
            }
            //can preemptive
            for(int i=0;i <100000;i++){}
        }

         public static void main(String[] args) {
            ProducerNConsumer Syc = new ProducerNConsumer();
            Thread thread0 = new Thread(Syc);
            Thread thread1 = new Thread(Syc);

            thread0.start();
            thread1.start();

            try{
                    thread0.join();
                    thread1.join();
            }catch(InterruptedException e){}
        }
}
