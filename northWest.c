#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int no_supply_points, no_demand_points, total_cost = 0;
    printf("Enter number of supply points: ");
    scanf("%d",&no_supply_points);
    int supply_point[no_supply_points];
    for(int i=0;i<no_supply_points;i++){
        printf("Enter availabality at supply point-%d: ",i+1);
        scanf("%d",(supply_point+i));
    }

    printf("Enter number of demand points: ");
    scanf("%d",&no_demand_points);
    int demand_point[no_demand_points];
    for(int i=0;i<no_demand_points;i++){
        printf("Enter demand at demand point-%d: ",i+1);
        scanf("%d",(demand_point+i));
    }

    int weight[no_supply_points][no_demand_points],distribution[no_supply_points][no_demand_points];
    for(int i=0;i<no_supply_points;i++){
        for(int j=0;j<no_demand_points;j++){
            printf("Enter per unit transportation expense from supply point-%d to demand point-%d: ",i+1, j+1);
            scanf("%d",&weight[i][j]);
        }
    }

    for(int i=0;i<no_supply_points;i++){
        if(supply_point[i]==0){
            continue;
        }
        for(int j=0;j<no_demand_points;j++){
            if(demand_point[j]==0){
                continue;
            }
            int temp = demand_point[j] < supply_point[i] ? demand_point[j] : supply_point[i];
            demand_point[j] -= temp;
            supply_point[i] -= temp;
            total_cost += weight[i][j]*temp;

        }
    }

    printf("Total cost occured: %d", total_cost);

}