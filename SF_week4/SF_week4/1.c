#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxN 1000

int hashtable[MaxN] = { 0 };

// ��ϣ��������������
int find_index(int in) {
    return in % MaxN;
}

int main() {
    int in;
    // ѭ����ȡ���룬ֱ���������з�
    while (scanf("%d", &in) == 1) {
        int index = find_index(in);
        // �����ϣ��ͻ��ʹ������̽�ⷨ
        while (hashtable[index] != 0 && hashtable[index] != in) {
            index = (index + 1) % MaxN;
        }
        // �����λ��Ϊ�գ���Ǹñ���ѳ���
        if (hashtable[index] == 0) {
            hashtable[index] = in;
        }
        // �����λ���Ѿ��Ǹñ�ţ�˵���ҵ����ظ����
        else {
            printf("%d", in);
            return 0;
        }
    }
    return 0;
}