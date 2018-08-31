package source;

import java.util.List;
import java.util.Scanner;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.transaction.Transactional;
import org.springframework.beans.factory.annotation.Autowired;

public class HelicopterService implements HelicopterProvider{

	@Autowired
	private HelicopterRepository helicopterRepository;

	@Autowired
	private PeopleRepository peopleRepository;

	@Autowired
	private BaseRepository baseRepository;

	@PersistenceContext
	private EntityManager em;
	

	@Override
	public List<Helicopter> getAll() {
		return helicopterRepository.findAll();
	}

	@Override
	public Helicopter getOne() {
		Scanner in = new Scanner(System.in);
		this.getAll().forEach(System.out::println);
		System.out.print("Enter id of helicopter to choose : ");
		long id = in.nextLong();
		 
		return helicopterRepository.findOne(id);
	}

	@Override
	@Transactional
	public void addOne() {
		System.out.println("*** add helicopter  ***");
		Helicopter helicopter = new Helicopter();

		Scanner in = new Scanner(System.in);
		System.out.println("Choosing base : ");
		baseRepository.findAll().forEach(System.out::println);
		System.out.println("Choose id of base : ");
		long baseId = in.nextLong();
		in.nextLine();
		Base base = baseRepository.findOne(baseId);
		helicopter.setBase(base);
		
		System.out.println("Choosing people : ");
		peopleRepository.findAll().forEach(System.out::println);
		System.out.println("Choose id of people: ");
		long peopleId = in.nextLong();
		in.nextLine();
		People people = peopleRepository.findOne(peopleId);
		helicopter.setPeople(people);

		System.out.print("Enter the lifetime : ");
		Integer lifetime = in.nextInt();
		helicopter.setLifetime(lifetime);

		System.out.print("Enter the rateOfClimb ");
		Integer rateOfClimb = in.nextInt();
		helicopter.setRateOfClimb(rateOfClimb);
		em.persist(helicopter);
		 
	}

	@Override
	@Transactional
	public void deleteOne() {
		System.out.println("*** delete chair ***");
		Helicopter deleted = this.getOne();
		helicopterRepository.delete(deleted.getId());
	}

	@Override
	@Transactional
	public void updateOne() {
		Scanner in = new Scanner(System.in);
		System.out.println("*** update chair ***");
		Helicopter updated = this.getOne();
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
		System.out.print("Enter new lifetime (to skip enter '-1'): ");
		Integer rateOfClimb = in.nextInt();
		if (lifetime != -1) {
			updated.setRateOfClimb(rateOfClimb);
		}
		em.merge(updated);
		 
	}

	
}