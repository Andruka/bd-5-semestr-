package source;


import java.util.List;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface TankRepository extends CrudRepository<Tank, Long> {
    List<Tank> findAll();
    Tank findOne(Long id);
}