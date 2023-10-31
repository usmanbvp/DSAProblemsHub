#include <iostream>
#include <queue>

class PrintSpooler {
private:
    std::queue<std::string> printQueue;
public:
    void addPrintJob(const std::string& job) {
        printQueue.push(job);
        std::cout << "Added print job: " << job << std::endl;
    }

    void printNextJob() {
        if (!printQueue.empty()) {
            std::string job = printQueue.front();
            printQueue.pop();
            std::cout << "Printing: " << job << std::endl;
        } else {
            std::cout << "Print queue is empty." << std::endl;
        }
    }
};

int main() {
    PrintSpooler spooler;
    spooler.addPrintJob("Document1.pdf");
    spooler.addPrintJob("Image.jpg");
    spooler.addPrintJob("Spreadsheet.xlsx");

    std::cout << "Printing jobs:" << std::endl;
    spooler.printNextJob();
    spooler.printNextJob();
    spooler.printNextJob();
    spooler.printNextJob();

    return 0;
}
