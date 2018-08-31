package source;

import java.util.List;

public interface CarProvider {

    void addOne();
    Car getOne();
    List<Car> getAll();
    void deleteOne();
    void updateOne();
	
}
