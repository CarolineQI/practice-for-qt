#include <stdio.h>
#include <mysql.h>
//���MySQL��64λ��vs�ı���ģʽҲ����64λ������
//���MySQL��32λ��vs�ı���ģʽҲ����32λ������
//�Ϸ���ͼ������
//#include <mysql.h> �������ok�Ϳ���ֱ�Ӱ�������ļ�
int main(void)
{
	MYSQL mysql;    //һ�����ݿ�ṹ��
	MYSQL_RES* res; //һ��������ṹ��
	MYSQL_ROW row;  //char** ��ά���飬���һ������¼
	//��ʼ�����ݿ�
	mysql_init(&mysql);
	//���ñ��뷽ʽ
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	//�ж��������ʧ�ܾ��������ʧ�ܡ�
	//ע�������ӵ��˻�������
	if (mysql_real_connect(&mysql, "localhost", "root", "123456", "worker", 3306, NULL, 0) == NULL)
		printf("����ʧ�ܣ�\\n");
	//ע�������ӵ��˻�������
			//ע�������ӵ��˻�������
					//ע�������ӵ��˻�������
							//ע�������ӵ��˻�������
//��ѯ����
	mysql_query(&mysql, "select * from t_worker");
	//��ȡ�����
	res = mysql_store_result(&mysql);
	//��ʾ����
	printf("ID\\t����\\t����\\t�������� \\n");
	//��ROW��ֵ���ж�ROW�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݡ�
	while (row = mysql_fetch_row(res))
	{
		printf("%s  ", row[0]);//��ӡID
		printf("\\t%s  ", row[1]);//��ӡ����
		printf("\\t%s  ", row[2]);//��ӡ����
		printf("\\t%s  ", row[3]);//��ӡ����
	}
	//�ͷŽ����
	mysql_free_result(res);
	//�ر����ݿ�
	mysql_close(&mysql);
	//ͣ���ȴ�
	system("pause");
	return 0;
}
