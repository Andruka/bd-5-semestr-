package source;

import org.springframework.beans.factory.annotation.Autowired;
import javax.persistence.EntityManager;
import javax.transaction.Transactional;
import java.util.List;
import java.util.Scanner;

public class PeopleService implements PeopleProvider{
    @Autowired
    private PeopleRepository peopleRepository;

    @Autowired
    private EntityManager em;

    @Override
    @Transactional
    public void addOne() {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the firstName : ");
        String firstName= in.nextLine();
        System.out.print("Enter the lastName : ");
        String lastName = in.nextLine();
        People newpeople = new People();
        newpeople.setFirstName(firstName);
        newpeople.setLastName(lastName);
        em.persist(newpeople);
    }

    @Override
    @Transactional
    public People getOne() {
        Scanner in = new Scanner(System.in);
        this.getAll().forEach(r -> {
            System.out.println(r);
        });
        System.out.print("Enter the id of room to choose : ");
        long id = in.nextLong();
         
        return peopleRepository.findOne(id);
    }

    @Override
    @Transactional
    public List<People> getAll() {
        return peopleRepository.findAll();
    }

    @Override
    @Transactional
    public void deleteOne() {
    	People people = this.getOne();
    	peopleRepository.delete(people.getId());
    }

    @Override
    @Transactional
    public void updateOne() {
        Scanner in = new Scanner(System.in);
        People updated = this.getOne();
        System.out.print("Enter new firstName (enter '!' to skip): ");
        String firstName = in.nextLine();
        if (!firstName.equals("!")) {
            updated.setFirstName(firstName);
        }
        System.out.print("Enter new lastName (enter '!' to skip): ");
        String lastName = in.nextLine();
        if (!lastName.equals("!")) {
            updated.setLastName(lastName);
        }
        em.merge(updated);
         
    }

    @Override
    @Transactional
    public void showAllPeople() {
    	People people = this.getOne();
    	people.getAircrafts().forEach(System.out::println);
    	people.getCars().forEach(System.out::println);
    	people.getHelicopters().forEach(System.out::println);
    	people.getTanks().forEach(System.out::println);
    }

    @Override
    @Transactional
    public void showOnePeople() {
        Scanner in = new Scanner(System.in);
        People people = this.getOne();
        System.out.println("1) Show all chairs");
        System.out.println("2) Show all tables");
        System.out.println("3) Show all computers");
        System.out.println("4) Show all servers");
        int sub = in.nextInt();
         
        if (sub < 0 || sub > 4) {
            System.out.println("Incorrect value");
            return;
        }
        switch (sub) {
            case 1:
            	people.getAircrafts().forEach(System.out::println);
                break;
            case 2:
            	people.getCars().forEach(System.out::println);
                break;
            case 3:
            	people.getHelicopters().forEach(System.out::println);
                break;
            case 4:
            	people.getTanks().forEach(System.out::println);
                break;
        }
    }

    @Override
    @Transactional
    public void search() {
        Scanner in = new Scanner(System.in);
        System.out.println("1) Find all transport for people");
        System.out.println("2) Find one transport for people");
        int subChoseFindRoom = in.nextInt();
         
        if (subChoseFindRoom < 1 || subChoseFindRoom > 2) {
            System.out.println("Incorrect value");
            return;
        }
        switch (subChoseFindRoom) {
            case 1:
                this.showAllPeople();
                break;
            case 2:
                this.showOnePeople();
                break;
        }
    }
}
