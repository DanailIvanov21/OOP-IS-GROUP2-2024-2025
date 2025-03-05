#include "Patient.h"
constexpr unsigned SIZE = 5;

int main() {
    Patient patients[SIZE];

    addPatients(patients, SIZE);
    sortPatientsByAge(patients, SIZE);
    printPatients(patients, SIZE);

    std::cout << "Critical patients count: " << countCriticalPatients(patients, SIZE) << std::endl;

    std::cout << "Patients under treatment:\n";
    filterByStatus(patients, SIZE, PatientStatus::UNDER_TREATMENT);

    Patient youngest = findYoungestUnderTreatment(patients, SIZE);
    printPatient(youngest);

    return 0;
}
