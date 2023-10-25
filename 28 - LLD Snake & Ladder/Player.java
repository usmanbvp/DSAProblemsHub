public class Player {
    private String name;
    private int position;

    public String getUsername() {
        return name;
    }

    public void setUsername(String name) {
        this.name = name;
    }

    public int getPosition() {
        return position;
    }

    public void setPosition(int position) {
        this.position = position;
    }

    public Player(String name, int position){
        this.name = name;
        this.position = position;
    }
}