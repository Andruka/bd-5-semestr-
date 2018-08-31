package source;

import java.util.List;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface BaseRepository extends CrudRepository<Base, Long> {
    List<Base> findAll();
    Base findOne(Long id);
}