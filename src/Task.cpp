#include "Task.h"
#include <iostream>

Task::Task(const std::string& title, const std::string& description, const std::string& priority, const std::string& deadline)
    : title(title), description(description), priority(priority), deadline(deadline), isCompleted(false) {}

std::string Task::getTitle() const { return title; }
std::string Task::getDescription() const { return description; }
std::string Task::getPriority() const { return priority; }
std::string Task::getDeadline() const { return deadline; }
bool Task::getStatus() const { return isCompleted; }

void Task::setTitle(const std::string& title) { this->title = title; }
void Task::setDescription(const std::string& description) { this->description = description; }
void Task::setPriority(const std::string& priority) { this->priority = priority; }
void Task::setDeadline(const std::string& deadline) { this->deadline = deadline; }
void Task::setStatus(bool status) { isCompleted = status; }

void Task::display() const {
    std::cout << "Titre       : " << title << "\n"
              << "Description : " << description << "\n"
              << "Priorité    : " << priority << "\n"
              << "Deadline    : " << deadline << "\n"
              << "Statut      : " << (isCompleted ? "Terminée" : "En cours") << "\n";
}
