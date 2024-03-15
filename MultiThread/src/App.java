public class App {
    public static void main(String[] args) throws Exception {

        MultithreadThing myThread = new MultithreadThing();
        MultithreadThing myThread2 = new MultithreadThing();

        myThread2.run();
        myThread.start();
    }
}
