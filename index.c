#include <stdio.h>
#include <string.h>

int main()
{
    char *hari[5] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat"};
    char jadwal[5][10][30];
    int jumlahJam[5] = {0};
    int pilihan, adaMapel, h, j;

    do
    {
        printf("\n=== MENU JADWAL MINGGUAN ===\n");
        printf("1. Tambah / Update Jadwal\n");
        printf("2. Lihat Jadwal\n");
        printf("3. Ubah Mata Pelajaran\n");
        printf("4. Hapus Jadwal Hari Tertentu\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            for (int i = 0; i < 5; i++)
            {
                printf("\nApakah hari %s ada pelajaran? (1 = ya, 0 = tidak): ", hari[i]);
                scanf("%d", &adaMapel);

                if (adaMapel == 1)
                {
                    printf("Berapa jam pelajaran di hari %s? ", hari[i]);
                    scanf("%d", &jumlahJam[i]);

                    for (int j = 0; j < jumlahJam[i]; j++)
                    {
                        printf("  Masukkan nama mapel jam ke-%d: ", j + 1);
                        scanf(" %[^\n]", jadwal[i][j]);
                    }
                }
                else
                {
                    jumlahJam[i] = 0; // kosong
                }
            }
            break;

        case 2:
            printf("\n=== JADWAL KULIAH ===\n");
            for (int i = 0; i < 5; i++)
            {
                printf("\n%s:\n", hari[i]);
                if (jumlahJam[i] == 0)
                {
                    printf("  (Tidak ada pelajaran)\n");
                }
                else
                {
                    for (int j = 0; j < jumlahJam[i]; j++)
                    {
                        printf("  Jam ke-%d: %s\n", j + 1, jadwal[i][j]);
                    }
                }
            }
            break;

        case 3:
            printf("\nHari ke berapa yang mau diubah (1-5): ");
            scanf("%d", &h);
            h--;
            if (h < 0 || h > 4 || jumlahJam[h] == 0)
            {
                printf("Hari tidak valid atau belum ada pelajaran.\n");
            }
            else
            {
                printf("Masukkan jam ke berapa yang mau diubah (1-%d): ", jumlahJam[h]);
                scanf("%d", &j);
                j--;
                if (j >= 0 && j < jumlahJam[h])
                {
                    printf("Masukkan nama mapel baru: ");
                    scanf(" %[^\n]", jadwal[h][j]);
                    printf("Mapel berhasil diupdate!\n");
                }
                else
                {
                    printf("Jam tidak valid.\n");
                }
            }
            break;

        case 4:
            printf("\nHari ke berapa yang mau dihapus (1-5): ");
            scanf("%d", &h);
            h--;
            if (h >= 0 && h < 5)
            {
                jumlahJam[h] = 0;
                printf("Jadwal hari %s dihapus!\n", hari[h]);
            }
            else
            {
                printf("Input tidak valid.\n");
            }
            break;

        case 0:
            printf("Program selesai. Sampai jumpa!\n");
            break;

        default:
            printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);

    return 0;
}
