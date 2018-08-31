package source;

import java.util.List;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface SpaceshipRepository extends CrudRepository<Spaceship, Long> {
    List<Spaceship> findAll();
    Spaceship findOne(Long id);
}
 