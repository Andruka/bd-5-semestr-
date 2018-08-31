package source;
import java.util.List;

public interface HelicopterProvider {

    void addOne();
    Helicopter getOne();
    List<Helicopter> getAll();
    void deleteOne();
    void updateOne();
	
}
