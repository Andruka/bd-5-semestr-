package source;

import java.util.List;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface HelicopterRepository extends CrudRepository<Helicopter, Long> {
    List<Helicopter> findAll();
    Helicopter findOne(Long id);
}