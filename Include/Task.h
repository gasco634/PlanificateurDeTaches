#ifndef TASK_HPP
#define TASK_HPP

#include <string>

class Task {
private:
    std::string title;
    std::string description;
    std::string priority;
    std::string deadline;
    bool isCompleted;

public:
    Task(const std::string& title, const std::string& description, const std::string& priority, const std::string& deadline);

    // Getters et setters
    std::string getTitle() const;
    std::string getDescription() const;
    std::string getPriority() const;
    std::string getDeadline() const;
    bool getStatus() const;

    void setTitle(const std::string& title);
    void setDescription(const std::string& description);
    void setPriority(const std::string& priority);
    void setDeadline(const std::string& deadline);
    void setStatus(bool status);

    // Afficher une tâche
    void display() const;
};

#endif
