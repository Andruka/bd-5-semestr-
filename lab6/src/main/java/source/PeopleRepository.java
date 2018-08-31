package source;

import java.util.List;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface PeopleRepository extends CrudRepository<People, Long> {
    List<People> findAll();
    People findOne(Long id);
}