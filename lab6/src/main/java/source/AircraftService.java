package source;

import java.util.List;
import java.util.Scanner;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.transaction.Transactional;
import org.springframework.beans.factory.annotation.Autowired;

public class AircraftService implements AircraftProvider{

	@Autowired
	private AircraftRepository aircraftRepository;

	@Autowired
	private PeopleRepository peopleRepository;

	@Autowired
	private BaseRepository baseRepository;

	@PersistenceContext
	private EntityManager em;
	

	@Override
	public List<Aircraft> getAll() {
		return aircraftRepository.findAll();
	}

	@Override
	public Aircraft getOne() {
		Scanner in = new Scanner(System.in);
		this.getAll().forEach(System.out::println);
		System.out.print("Enter id of aircraft to choose : ");
		long id = in.nextLong();
		return aircraftRepository.findOne(id);
	}

	@Override
	@Transactional
	public void addOne() {
		System.out.println("*** add aircraft  ***");
		Aircraft aircraft = new Aircraft();

		Scanner in = new Scanner(System.in);
		System.out.println("Choosing base : ");
		baseRepository.findAll().forEach(System.out::println);
		System.out.println("Choose id of base : ");
		long baseId = in.nextLong();
		in.nextLine();
		Base base = baseRepository.findOne(baseId);
		aircraft.setBase(base);
		
		System.out.println("Choosing people : ");
		peopleRepository.findAll().forEach(System.out::println);
		System.out.println("Choose id of people: ");
		long peopleId = in.nextLong();
		in.nextLine();
		People people = peopleRepository.findOne(peopleId);
		aircraft.setPeople(people);

		System.out.print("Enter the lifetime : ");
		Integer lifetime = in.nextInt();
		aircraft.setLifetime(lifetime);

		System.out.print("Enter the range ");
		Integer range = in.nextInt();
		aircraft.setRange(range);
		em.persist(aircraft);
	}

	@Override
	@Transactional
	public void deleteOne() {
		System.out.println("*** delete chair ***");
		Aircraft deleted = this.getOne();
		aircraftRepository.delete(deleted.getId());
	}

	@Override
	@Transactional
	public void updateOne() {
		Scanner in = new Scanner(System.in);
		System.out.println("*** update chair ***");
		Aircraft updated = this.getOne();
		peopleRepository.findAll().forEach(System.out::println);
		System.out.print("Enter new  people (to skip enter '!'): ");
		String peopleId = in.nextLine();
		if (!peopleId.equals("!")) {
			long id = Long.parseLong(peopleId);
			updated.setPeople(peopleRepository.findOne(id));
		}
		baseRepository.findAll().forEach(System.out::println);
		System.out.print("Enter new  base (to skip enter '!'): ");
		String baseId = in.nextLine();
		if (!baseId.equals("!")) {
			long id = Long.parseLong(baseId);
			updated.setBase(baseRepository.findOne(id));
		}

		System.out.print("Enter new lifetime (to skip enter '-1'): ");
		Integer lifetime = in.nextInt();
		if (lifetime != -1) {
				updated.setLifetime(lifetime);		
		}
		System.out.print("Enter new range (to skip enter '-1'): ");
		Integer range = in.nextInt();
		if (lifetime != -1) {
			updated.setRange(range);
		}
		em.merge(updated);
	}
}
