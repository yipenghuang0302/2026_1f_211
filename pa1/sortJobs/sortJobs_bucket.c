#include <stdio.h>
#include <stdlib.h>

int n; // Array size
int nb; // Number of buckets
int cap; // Bucket capacity

struct Node {
  int data;
  struct Node *next;
};

void deleteList(struct Node* head)
{
    struct Node* prev = head;
 
    while (head)
    {
        head = head->next;
        free(prev);
        prev = head;
    }
}

//function to print linked list
void printlist(struct Node* head)
{
	while (head != NULL) {
		printf("%d->", head->data);
		head = head->next;
	}
	printf("NULL");
}

void push(struct Node **bucket, int val)
{
	/* allocate node */
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = val;
	/* link the old list off the new node */
	newnode->next = *bucket;
	/* move the job_head to point to the new node */
	*bucket = newnode;
  // newnode = NULL;
  // free(newnode);
}

void print(int ar[]) {
  int i;
  for (i = 0; i < n; ++i) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

// Print buckets
void printBuckets(struct Node *list) {
  struct Node *cur = list;
  while (cur) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
}

int getBucketIndex(int value) {
  return value / cap;
}

struct Node** InsertionSort(struct Node *list, struct Node *list2) {
  struct Node *k, *k2, *end_list, *job_list;
  struct Node **temp;

  // Create buckets and allocate memory size
  //temp to return both sorted linked lists
  temp = (struct Node **)malloc(sizeof(struct Node *) * 2);
  if (list == 0 || list->next == 0) {
    // return list, list2;
    temp[0] = list;
    temp[1] = list2;
    return temp;
  }

  end_list = list;
  job_list = list2;
  // printlist(end_list);
  // printf("\n");
  k = list->next;
  k2 = list2->next;
  end_list->next = 0;
  job_list->next = 0;
  while (k != 0) {
    struct Node *ptr;
    struct Node *ptr2;
    if (end_list->data >= k->data) {
      struct Node *tmp;
      struct Node *tmp2;
      tmp = k;
      tmp2 = k2;
      k = k->next;
      k2 = k2->next;
      tmp->next = end_list;
      tmp2->next = job_list;
      end_list = tmp;
      job_list = tmp2;
      continue;
    }
    
    for (ptr = end_list, ptr2 = job_list; ptr->next != 0; ptr = ptr->next, ptr2 = ptr2->next) {
      if (ptr->next->data >= k->data)
        break;
    }
    
    if (ptr->next != 0) {
      struct Node *tmp;
      struct Node *tmp2;
      tmp = k;
      tmp2 = k2;
      k = k->next;
      k2 = k2->next;
      tmp->next = ptr->next;
      tmp2->next = ptr2->next;
      ptr->next = tmp;
      ptr2->next = tmp2;
      continue;
    } else {
      ptr->next = k;
      ptr2->next = k2;
      k = k->next;
      k2 = k2->next;
      ptr->next->next = 0;
      ptr2->next->next = 0;
      continue;
    }
  }
  temp[0] = end_list;
  temp[1] = job_list;
  return temp;
}


// Sorting function
void BucketSort(int arr[],int arr2[]) {

  int i, j;
  struct Node **buckets;
  struct Node **buckets2;

  // Create buckets and allocate memory size
  buckets = (struct Node **)malloc(sizeof(struct Node *) * nb); //bucket for end time
  buckets2 = (struct Node **)malloc(sizeof(struct Node *) * nb); //bucket for job time

  // Initialize empty buckets
  for (i = 0; i < nb; ++i) {
    buckets[i] = NULL;
    buckets2[i] = NULL;
  }

  // Fill the buckets with respective elements
  
  
  for (i = 0; i < n; ++i) {
    int pos = getBucketIndex(arr[i]);

    push(&buckets[pos],arr[i]);
    push(&buckets2[pos],arr2[i]);
  }

  // Sort the elements of both buckets based on values of end bucket
  for (i = 0; i < nb; ++i) {
    struct Node **a = InsertionSort(buckets[i],buckets2[i]);
    buckets[i] = a[0];
    buckets2[i] = a[1];
    free(a);
    // printlist(buckets2[i]);
  }


  // Put sorted elements on arr
  for (j = 0, i = 0; i < nb; ++i) {
    struct Node *node;
    struct Node *node2;
    node = buckets[i];
    node2 = buckets2[i];
    while (node) {
      arr[j] = node->data;
      arr2[j] = node2->data;
      j++;
      node = node->next;
      node2 = node2->next;
    }
  }

  for (i = 0; i < nb; ++i) {
    deleteList(buckets[i]);
    deleteList(buckets2[i]);
    // printlist(buckets2[i]);
  }

  free(buckets);
  free(buckets2);
  // free(current);
  // free(current2);
  return;
}

// Driver code
int main(int argc, char* argv[]) {
  // Struct tmmp;
  n = 0;
  nb = 6;
  cap = 20;
  
  FILE* fp = fopen(argv[1], "r");
  if (!fp) {
      perror("fopen failed");
      exit(EXIT_FAILURE);
  }

  char buf[256];

  // Read the number of jobs to be scheduled
  if (!fscanf(fp, "%s\n", buf)) {
      perror("reading the number of jobs failed");
      exit(EXIT_FAILURE);
  }
  int jobcount = atoi(buf);
  n = jobcount;
  
  int* arr = (int*)malloc(sizeof(int)*n);
  int* arr2 = (int*)malloc(sizeof(int)*n);
  
  // Next read the maximum number of timeslots
  if (!fscanf(fp, "%s\n", buf)) {
      perror("reading the number of timeslots failed");
      exit(EXIT_FAILURE);
  }
      // // Now read the rest of the file
  int b = 0;
  for ( int line=0; line<jobcount; line++ ) {

    if (!fgets(buf, 256, fp)) {
        perror("reading a line for a job failed");
        exit(EXIT_FAILURE);
    }

    char job;
    unsigned int end;
    if (!sscanf(buf, "%c %d", &job, &end)) {
        perror("parsing a line for a job failed");
        exit(EXIT_FAILURE);
    }
    
    arr[b] = (int)end;
    arr2[b] = (int)job;
    b++;
  }
  
  BucketSort(arr, arr2);
  
  for (int i = 0; i < n; ++i) {
    printf("%c ", arr2[i]);
    printf("\n");
  }
  free(arr);
  free(arr2);
  fclose(fp);

  exit(EXIT_SUCCESS);
}