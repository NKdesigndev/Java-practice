public class MultithreadThing extends Thread{
    
        @Override
        public void run(){
            // Count number to 5
            for(int i = 1; i <=5; i++){
                System.out.println(i);

                try{
                    Thread.sleep(1000);
                }catch(InterruptedException e){
                    System.out.println(e);
                }

            }
        }
}
