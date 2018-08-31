package source;

import java.util.List;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface AircraftRepository extends CrudRepository<Aircraft, Long> {
    List<Aircraft> findAll();
    Aircraft findOne(Long id);
}
 