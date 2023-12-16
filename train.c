#include<stdio.h>
int travel,choice,no_of_passengers;
char com1[][3]={"S1","S2"};
char com2[][3]={"A1","A2","A3","B1","B2","B3"};
int Seat_number[50];
struct train
{
    char train_name[50];
    int train_number;
    
}s1[]={"Pothigai Express",16101,"Covai Express",16102,"Kannyakumari Express",16103};
struct passenger
{
    char name[25],gender[10];
    int age;
    long int Ph_no;
}s2[50];
void print_seats(int);
void Seats(int);
void Travelling_Route();
void Class(int);
void seats();
void First_class();
void Second_class();
void print_detail_First_class(int);
void print_detail_Second_class(int);
void input_passenger(int);
void print_passenger(int);
void main()
{
    printf("\tTrain Ticket Reservation\n");
    Travelling_Route();
}
void Travelling_Route()
{
    printf("\nPress 1 : Sivakasi to Chennai \n");
    printf("press 2 : Sivakasi to Coimbatore \n");
    printf("Press 3 : Sivakasi to Kannyakumari \n");
    printf("\nEnter your choice : ");
    scanf("%d",&travel);
    printf("\n");
    Class(travel);
}
void Class(int x)
{
    again:
    switch(x)
    {
        case 1:
            printf("\nPress 1 : First Class[S1/S2] Rs-$500\n");
            printf("Press 2 : Second Class[A1/A2/A3/B1/B2/B3] Rs-$400\n");
            break;
        case 2:
            printf("\nPress 1 : First Class[S1/S2] Rs-$450\n");
            printf("Press 2 : Second Class[A1/A2/A3/B1/B2/B3] Rs-$350\n");
            break;
        case 3:
            printf("\nPress 1 : First Class[S1/S2] Rs-$400\n");
            printf("Press 2 : Second Class[A1/A2/A3/B1/B2/B3] Rs-$300\n");
            break;
        default:
            printf("Invalid !\n");
            break;
    }
    while(x>3)
        goto again;
    printf("\nEnter your Choice : ");
    scanf("%d",&choice);
    printf("\n");
    seats(choice);
}
void seats(int x)
{
    again:
    switch(x)
    {
        case 1:
            First_class();
            break;
        case 2:
            Second_class();
            break;
        default:
            printf("\nInvalid !\n");
            break;
    }
    while(x>2)
    {
        goto again;
    }
}
void First_class()
{
    printf("\nEnter How many tickets going to be reserved : ");
    scanf("%d",&no_of_passengers);
    printf("\n\n");
    input_passenger(no_of_passengers);
    printf("\tReservation Successful...\n");
    if(travel==1)
    {
        int Rs=500*no_of_passengers;
        printf("\nxxxxxxxxxx TICKET xxxxxxxxx");
        printf("\nTrain Name : %s",s1[0].train_name);
        printf("\nTrain Number : %d\n",s1[0].train_number);
        print_detail_First_class(Rs);
    }
    else if(travel==2)
    {
        int Rs=450*no_of_passengers;
        printf("\nxxxxxxxxxx TICKET xxxxxxxxx");
        printf("\nTrain Name : %s",s1[1].train_name);
        printf("\nTrain Number : %d\n",s1[1].train_number);
        print_detail_First_class(Rs);
    }
    else
    {
        int Rs=400*no_of_passengers;
        printf("\nxxxxxxxxxx TICKET xxxxxxxxx");
        printf("\nTrain Name : %s",s1[2].train_name);
        printf("\nTrain Number : %d\n",s1[2].train_number);
        print_detail_First_class(Rs);
    }
}
void Second_class()
{
    printf("\nEnter How many tickets going to be reserved : ");
    scanf("%d",&no_of_passengers);
    printf("\n\n");
    input_passenger(no_of_passengers);
    printf("\n\n\t\tReservation Successful...\n");
    if(travel==1)
    {
        int Rs=400*no_of_passengers;
        printf("\nxxxxxxxxxx TICKET xxxxxxxxx");
        printf("\nTrain Name : %s",s1[0].train_name);
        printf("\nTrain Number : %d\n",s1[0].train_number);
        print_detail_Second_class(Rs);
    }
    else if(travel==2)
    {
        int Rs=350*no_of_passengers;
        printf("\nxxxxxxxxxx TICKET xxxxxxxxx");
        printf("\nTrain Name : %s",s1[1].train_name);
        printf("\nTrain Number : %d\n",s1[1].train_number);
        print_detail_Second_class(Rs);
    }
    else
    {
        int Rs=300*no_of_passengers;
        printf("\nxxxxxxxxxx TICKET xxxxxxxxx");
        printf("\nTrain Name : %s",s1[2].train_name);
        printf("\nTrain Number : %d\n",s1[2].train_number);
        print_detail_Second_class(Rs);
    }
}
void input_passenger(int x)
{
    Seats(no_of_passengers);
    for(int i=0;i<x;i++)
    {
        printf("\nEnter Details of Passenger %d:-\n",i+1);
        printf("Name : ");
        scanf("%s",s2[i].name);
        printf("\nGender [Male/Female] : ");
        scanf("%s",s2[i].gender);
        printf("\nAge : ");
        scanf("%d",&s2[i].age);
        printf("\n");
    }
    printf("\nContact info : ");
    scanf("%ld",&s2[0].Ph_no);
}
void print_detail_First_class(int x)
{
    printf("Amount : $%d\n",x);
    printf("Seats Allocated in %s : ",com1[rand()%2]);
    print_seats(no_of_passengers);
    printf("seat\nCustomer care : 8015978080\n");
    printf("\n\tPassenger Details...\n");
    print_passenger(no_of_passengers);
}
void print_detail_Second_class(int x)
{
    printf("Amount : $%d\n",x);
    printf("Seats Allocated in %s : ",com1[rand()%6]);
    print_seats(no_of_passengers);
    printf("seat\nCustomer care : 8015978080\n");
    printf("\n\tPassenger Details...\n");
    print_passenger(no_of_passengers);
}
void print_passenger(int x)
{
    for(int i=0;i<x;i++)
    {
        printf("\nName : %s",s2[i].name);
        printf("\nGender : %s",s2[i].gender);
        printf("\nAge : %d",s2[i].age);
        printf("\n\n");
    }
    printf("\nContact info : %ld",s2[0].Ph_no);
}
void Seats(int x)
{
    int i,j;
    static int seat_number[50];
    for(i=0;i<50;i++)
    {
        seat_number[i]=0;
    }
    for(i=0;i<x;i++)
    {
        again:
        Again:
        printf("Enter seat number[1-50] for passenger %d : ",i+1);
        scanf("%d",&Seat_number[i]);
        
        for(j=0;j<50;j++)
        {
            
            if(Seat_number[i]==j)
            {
                if(seat_number[j] == Seat_number[i]){
                    printf("Seat already booked. Please choose another \n");
                    goto Again;
                }
                seat_number[j] = Seat_number[i];
                if(seat_number[j]==0)
                {
                    seat_number[j]==1;
                }
                // else
                // {
                //     printf("\nReserved Aldready ...\n");
                //     goto Again;
                // }
            }
            // if(Seat_number[i] == seat_number[j]){
            //     printf("Wront seat");
            // }
            
        }
    }
}
void print_seats(int x)
{
    for(int i=0;i<x;i++)
    {
        printf("%d ",Seat_number[i]);
    }
}
