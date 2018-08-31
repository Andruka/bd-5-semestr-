package source;

import javax.persistence.*;

@MappedSuperclass
@Table(name = "transport")
public class Transport {
	@Id
	@Column(name = "id")
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	protected Long id;

	@ManyToOne(optional = false)
	@JoinColumn(name = "base", nullable=false)
	protected Base base;

	public Base getBase() {
		return base;
	}

	public void setBase(Base base) {
		this.base = base;
	}

	@ManyToOne(optional = false)
	@JoinColumn(name = "people", nullable=false)
	protected People people;

	public People getPeople() {
		return people;
	}

	public void setPeople(People people) {
		this.people = people;
	}

	public Long getId() { return id;	}
	
	@Override
	public String toString() {
		return String.format("id=%d {%s}{ %s}", id, base, people);
	}
}
