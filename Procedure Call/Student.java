
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Student extends Remote {
    String getStudentInfo() throws RemoteException;
}