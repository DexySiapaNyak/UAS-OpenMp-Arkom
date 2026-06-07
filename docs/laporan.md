# Laporan Singkat

## Tujuan

Membandingkan waktu eksekusi antara pemrosesan sequential dan parallel menggunakan OpenMP.

## Metode

Array berisi 100 juta elemen bernilai 1.

Dilakukan:

1. Penjumlahan Sequential
2. Penjumlahan Parallel OpenMP

## Hasil

Contoh:

Sequential Time = 0.40 s

Parallel Time = 0.12 s

Speedup = 3.33x

## Analisis

OpenMP mampu mempercepat proses karena pekerjaan dibagi ke beberapa thread CPU.

## Kelebihan

- Implementasi sederhana
- Performa meningkat

## Kekurangan

- Ada overhead pembuatan thread
- Speedup tidak selalu linear

## Kesimpulan

OpenMP dapat meningkatkan performa komputasi dibandingkan metode sequential.