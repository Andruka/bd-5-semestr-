package source;

import java.util.List;

public interface TankProvider {
	
    void addOne();
    Tank getOne();
    List<Tank> getAll();
    void deleteOne();
    void updateOne();

}
