package source;

import java.util.List;

public interface AircraftProvider {
	
    void addOne();
    Aircraft getOne();
    List<Aircraft> getAll();
    void deleteOne();
    void updateOne();

}
