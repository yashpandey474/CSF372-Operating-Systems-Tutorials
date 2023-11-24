    write(fp, "operating systems", 5);
    lseek(fp, 2, SEEK_END);
    write(fp, "tutorial", 3);
    lseek(fp, 0, 0);