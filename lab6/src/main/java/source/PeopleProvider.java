package source;

import java.util.List;

public interface PeopleProvider {

	void addOne();
	People getOne();
	List<People> getAll();
	void deleteOne();
	void updateOne();
	void showAllPeople();
	void showOnePeople();
	void search();
	
}
