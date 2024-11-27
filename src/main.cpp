#include <iostream>
#include <vector>
#include <algorithm>
#include "Task.h"

std::vector<Task> tasks;

// Fonction pour ajouter une tâche
void addTask() {
    std::string title, description, priority, deadline;

    std::cout << "Titre : ";
    std::getline(std::cin, title);
    std::cout << "Description : ";
    std::getline(std::cin, description);
    std::cout << "Priorité : ";
    std::getline(std::cin, priority);
    std::cout << "Deadline : ";
    std::getline(std::cin, deadline);

    tasks.emplace_back(title, description, priority, deadline);
    std::cout << "Tâche ajoutée avec succès !\n";
}

// Fonction pour modifier une tâche existante
void editTask() {
    std::string title;
    std::cout << "Entrez le titre de la tâche à modifier : ";
    std::getline(std::cin, title);

    auto it = std::find_if(tasks.begin(), tasks.end(), [&title](const Task& task) {
        return task.getTitle() == title;
    });

    if (it != tasks.end()) {
        std::cout << "Nouvelle description : ";
        std::string description;
        std::getline(std::cin, description);
        it->setDescription(description);

        std::cout << "Nouvelle priorité : ";
        std::string priority;
        std::getline(std::cin, priority);
        it->setPriority(priority);

        std::cout << "Nouvelle deadline : ";
        std::string deadline;
        std::getline(std::cin, deadline);
        it->setDeadline(deadline);

        std::cout << "Tâche modifiée avec succès !\n";
    } else {
        std::cout << "Tâche non trouvée.\n";
    }
}

// Fonction pour supprimer une tâche
void deleteTask() {
    std::string title;
    std::cout << "Entrez le titre de la tâche à supprimer : ";
    std::getline(std::cin, title);

    auto it = std::remove_if(tasks.begin(), tasks.end(), [&title](const Task& task) {
        return task.getTitle() == title;
    });

    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        std::cout << "Tâche supprimée avec succès !\n";
    } else {
        std::cout << "Tâche non trouvée.\n";
    }
}

// Fonction pour marquer une tâche comme terminée ou en cours
void toggleTaskStatus() {
    std::string title;
    std::cout << "Entrez le titre de la tâche : ";
    std::getline(std::cin, title);

    auto it = std::find_if(tasks.begin(), tasks.end(), [&title](const Task& task) {
        return task.getTitle() == title;
    });

    if (it != tasks.end()) {
        it->setStatus(!it->getStatus());
        std::cout << "Statut de la tâche mis à jour avec succès !\n";
    } else {
        std::cout << "Tâche non trouvée.\n";
    }
}

// Fonction pour afficher toutes les tâches
void displayTasks() {
    for (const auto& task : tasks) {
        task.display();
        std::cout << "-----------------\n";
    }
}

// Fonction pour rechercher une tâche par mot-clé
void searchTasks() {
    std::string keyword;
    std::cout << "Entrez un mot-clé pour la recherche : ";
    std::getline(std::cin, keyword);

    for (const auto& task : tasks) {
        if (task.getTitle().find(keyword) != std::string::npos ||
            task.getDescription().find(keyword) != std::string::npos) {
            task.display();
            std::cout << "-----------------\n";
        }
    }
}

// Fonction pour afficher les tâches complétées ou en attente
void displayTasksByStatus(bool completed) {
    for (const auto& task : tasks) {
        if (task.getStatus() == completed) {
            task.display();
            std::cout << "-----------------\n";
        }
    }
}

// Menu principal
void menu() {
    while (true) {
        std::cout << "\n--- Planificateur de Tâches ---\n"
                  << "1. Ajouter une tâche\n"
                  << "2. Modifier une tâche\n"
                  << "3. Supprimer une tâche\n"
                  << "4. Marquer une tâche comme terminée/en cours\n"
                  << "5. Afficher toutes les tâches\n"
                  << "6. Rechercher des tâches\n"
                  << "7. Afficher les tâches terminées\n"
                  << "8. Afficher les tâches en attente\n"
                  << "0. Quitter\n"
                  << "Choix : ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Pour gérer les sauts de ligne dans `std::getline`

        switch (choice) {
        case 1: addTask(); break;
        case 2: editTask(); break;
        case 3: deleteTask(); break;
        case 4: toggleTaskStatus(); break;
        case 5: displayTasks(); break;
        case 6: searchTasks(); break;
        case 7: displayTasksByStatus(true); break;
        case 8: displayTasksByStatus(false); break;
        case 0: return;
        default: std::cout << "Choix invalide.\n"; break;
        }
    }
}

int main() {
    menu();
    return 0;
}
