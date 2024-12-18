
#include <iostream>
#include <queue> // Standard library for queue
using namespace std;

// Function to display the job queue
void displayQueue(queue<string> jobQueue) {
    if (jobQueue.empty()) {
        cout << "The job queue is empty." << endl;
        return;
    }

    cout << "Current Job Queue: ";
    while (!jobQueue.empty()) {
        cout << jobQueue.front() << " ";
        jobQueue.pop();
    }
    cout << endl;
}

int main() {
    queue<string> jobQueue; // Declare the job queue
    int choice;
    string job;

    do {
        // Menu
        cout << "\n--- Job Queue Simulation ---\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Job Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Add Job
                cout << "Enter job name: ";
                cin >> job;
                jobQueue.push(job); // Add job to the rear
                cout << "Job '" << job << "' added to the queue." << endl;
                break;

            case 2:
                // Delete Job
                if (jobQueue.empty()) {
                    cout << "No jobs in the queue to delete." << endl;
                } else {
                    cout << "Job '" << jobQueue.front() << "' completed and removed from the queue." << endl;
                    jobQueue.pop(); // Remove job from the front
                }
                break;

            case 3:
                // Display Job Queue
                displayQueue(jobQueue);
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}


