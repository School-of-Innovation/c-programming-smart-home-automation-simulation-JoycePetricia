#include <stdio.h>

void initializeSystem(int lights[], int temps[], int motion[], int locks[], int rooms) {
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;
        temps[i] = 25; // Default temperature
        motion[i] = 0;
        locks[i] = 1;
    }
    printf("System initialized with %d rooms.\n", rooms);
}

void toggleLight(int lights[], int rooms) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        lights[room - 1] = !lights[room - 1];
        printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
    } else {
        printf("Invalid room number!\n");
    }
}

void readTemperature(int temps[], int rooms) {
    int room;
    printf("Enter room number to check temperature (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        printf("Temperature in Room %d is %d°C.\n", room, temps[room - 1]);
    } else {
        printf("Invalid room number!\n");
    }
}

void detectMotion(int motion[], int rooms) {
    int room;
    printf("Enter room number to check motion sensor (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        printf("Motion in Room %d is %s.\n", room, motion[room - 1] ? "DETECTED" : "NOT DETECTED");
    } else {
        printf("Invalid room number!\n");
    }
}

void lockUnlockSystem(int locks[], int rooms) {
    int room;
    printf("Enter room number to lock/unlock door (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        locks[room - 1] = !locks[room - 1];
        printf("Security lock in Room %d is now %s.\n", room, locks[room - 1] ? "LOCKED" : "UNLOCKED");
    } else {
        printf("Invalid room number!\n");
    }
}

void analyzeHouseStatus(int lights[], int temps[], int motion[], int locks[], int rooms) {
    printf("\n===== House Status Summary =====\n");
    for (int i = 0; i < rooms; i++) {
        printf("Room %d: Light [%s], Temperature [%d°C], Motion [%s], Lock [%s]\n",
                i + 1,
                lights[i] ? "ON" : "OFF",
                temps[i],
                motion[i] ? "DETECTED" : "NOT DETECTED",
                locks[i] ? "LOCKED" : "UNLOCKED");
    }
}

int main() {
    int rooms;
    printf("Enter number of rooms: ");
    scanf("%d", &rooms);
   
    int lights[rooms], temps[rooms], motion[rooms], locks[rooms];
    initializeSystem(lights, temps, motion, locks, rooms);
   
    int choice;
    do {
        printf("\n===== Smart Home Menu =====\n");
        printf("1. Toggle Light\n2. Read Temperature\n3. Check Motion Sensor\n4. Lock/Unlock Security System\n5. House Status Summary\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
       
        switch (choice) {
            case 1: toggleLight(lights, rooms); break;
            case 2: readTemperature(temps, rooms); break;
            case 3: detectMotion(motion, rooms); break;
            case 4: lockUnlockSystem(locks, rooms); break;
            case 5: analyzeHouseStatus(lights, temps, motion, locks, rooms); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
   
    return 0;
}
