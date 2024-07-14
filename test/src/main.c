#include <logger.h>
#include <core/asserts.h>

int main(){
    PRWARN("Hello World %d", 31);
    PRERROR("Hello World %d", 11);
    PRINFO("INGPO World %d", 31);

    PRASSERT_MSG(0 == 1, "Blok Tolol");
    return 0;
}