import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class Server implements Student {

    public Server() {}

    public static void main(String args[]) {

        try {
            Server obj = new Server();
            Student stub = (Student) UnicastRemoteObject.exportObject(obj, 0);

            // Bind the remote object's stub in the registry
            Registry registry = LocateRegistry.getRegistry();
            registry.bind("Student", stub);

            System.err.println("Server ready");
        } catch (Exception e) {
            System.err.println("Server exception: " + e.toString());
            e.printStackTrace();
        }
    }

    @Override
    public String getStudentInfo() throws RemoteException {
        return "Name: Mezigebu Zework \n ID: ATR/0337/08 Department \n Department: Software Engineering";
    }
}