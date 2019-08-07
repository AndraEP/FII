package bananas;

import java.time.LocalDate;

class Essay extends Project
{
    private Topic topic;
    public Essay(String name, LocalDate deadline, Topic topic)
    {
        this.name = name;
        this.deadline = deadline;
        this.topic = topic;
    }
    public Topic getTopic()
    {
        return topic;
    }
    public void setTopic(Topic topic)
    {
        this.topic = topic;
    }
    public String toString()
    {
        return super.toString() + "Topic: " + topic + ")";
    }
    public boolean equals (Object obj)
    {
        if (obj == null) return false;
        if (!(obj instanceof Essay)) return false;
        Essay ess = (Essay) obj;
        if (!(super.equals(obj))) return false;
        if (!(topic.equals(ess.topic))) return false;
        return true;
    }
}
