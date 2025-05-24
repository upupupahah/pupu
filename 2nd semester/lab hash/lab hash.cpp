#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct UserData {
    std::string username;
    int user_id;
    double account_value;
    bool is_used;
};

struct DataContainer {
    std::vector<UserData> records;
    int conflict_count;
};

const int CONTAINER_CAPACITY = 100;

int computeHash(int uid, int max_size) {
    const double magic_number = 0.645763;
    double temp = uid * magic_number;
    return static_cast<int>(max_size * (temp - floor(temp)));
}

int getNextPosition(int start, int step, int limit) {
    return (start + step) % limit;
}

void initializeContainer(DataContainer* dc) {
    dc->records.resize(CONTAINER_CAPACITY);
    for (auto& item : dc->records) {
        item.is_used = false;
    }
    dc->conflict_count = 0;
}

void storeRecord(DataContainer* dc, int uid, const std::string& name, double value) {
    int base_idx = computeHash(uid, dc->records.size());
    int attempt = 0;

    while (attempt < dc->records.size()) {
        int current_idx = getNextPosition(base_idx, attempt, dc->records.size());

        if (!dc->records[current_idx].is_used) {
            dc->records[current_idx] = { name, uid, value, true };
            if (attempt > 0) dc->conflict_count += attempt;
            return;
        }
        ++attempt;
    }

    ++dc->conflict_count;
}

UserData* findRecord(DataContainer* dc, int uid) {
    int base_idx = computeHash(uid, dc->records.size());
    int attempt = 0;

    while (attempt < dc->records.size()) {
        int current_idx = getNextPosition(base_idx, attempt, dc->records.size());

        if (!dc->records[current_idx].is_used) break;

        if (dc->records[current_idx].user_id == uid) {
            return &dc->records[current_idx];
        }
        ++attempt;
    }

    return nullptr;
}

int main() {
    setlocale(LC_ALL, "ru");
    DataContainer db;
    initializeContainer(&db);

    const std::vector<std::pair<std::string, double>> users = {
        {"Соколов Артем Львович", 45231.87},
        {"Миронова Анна Владиславовна", 78456.12},
        {"Гордеев Максим Игоревич", 125487.33},
        {"Коваленко Ольга Сергеевна", 56321.45},
        {"Бессонов Денис Павлович", 98745.01}
    };

    for (size_t i = 0; i < users.size(); ++i) {
        storeRecord(&db, 5000 + i, users[i].first, users[i].second);
    }

    std::cout << "Обнаружено коллизий: " << db.conflict_count << "\n";

    while (true) {
        std::cout << "\nВведите ID: ";
        int search_id;
        std::cin >> search_id;

        if (search_id == 0) break;

        if (search_id < 5000 || search_id > 5004) {
            std::cout << "Неверный идентификатор!\n";
            continue;
        }

        UserData* result = findRecord(&db, search_id);
        if (result) {
            std::cout << "Найдена запись:\n"
                << "Владелец: " << result->username << "\n"
                << "ID: " << result->user_id << "\n"
                << "Средства: " << std::fixed << std::setprecision(2)
                << result->account_value << " руб.\n";
        }
        else {
            std::cout << "Запись не обнаружена\n";
        }
    }
    return 0;
}