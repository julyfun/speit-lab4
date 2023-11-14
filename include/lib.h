enum { MAX_LEN = (int)2e5 + 10 };

extern const char FUNC_NAMES[][50];
void (*FUNC[5])(int arr[], int len);

void rand_num(int arr[], int dim, int range);
void ivec_print_p1(int arr[], int len);

void bubble_sort(int arr[], int len);
void insertion_sort(int arr[], int len);
void selection_sort(int arr[], int len);
void merge_sort_api(int arr[], int len);
void quick_sort_api(int arr[], int len);
