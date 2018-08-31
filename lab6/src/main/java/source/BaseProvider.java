package source;

import java.util.List;

public interface BaseProvider {
	void addOne();
	Base getOne();
	List<Base> getAll();
	void deleteOne();
	void updateOne();
	void showAllBase();
	void showOneBase();
	void search();
}