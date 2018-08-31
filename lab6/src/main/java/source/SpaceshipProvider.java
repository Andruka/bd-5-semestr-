package source;

import java.util.List;

public interface SpaceshipProvider {
	
    void addOne();
    Spaceship getOne();
    List<Spaceship> getAll();
    void deleteOne();
    void updateOne();

}
