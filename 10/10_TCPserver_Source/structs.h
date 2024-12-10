#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdint.h>
#include <QTime>

//������������� ���������
#define ID 0xFFFE

//��� �������� ������ ������ ���������� ����������� ��������� ���������,
//����� �������� ������������ ������������� ������!

#pragma pack(push, 1)

//���� ��������� ������� ������������ ������
enum Messages {
    //��� �������� ����� ������������, 100� ��� �������, 200� ���������
    GET_TIME = 100,
    GET_SIZE = 101,
    GET_STAT = 102,

    SET_DATA = 200,
    CLEAR_SPACE = 201
};

//������� ���������
enum StatusMessages {

    STATUS_SUCCES = 1,

    ERR_NO_FREE_SPACE = 10, // ������������ ���������� �����
    ERR_ZERO_LEN = 11
};

/*!
 * \brief �������� ��������� ��������� ��������� ������
 */
struct ServiceHeader {

    uint16_t id = ID;     //������������� ������ ������
    uint16_t idData = 0;  //������������� ���� ������
    uint8_t status = 0;   //������ ���������, ���� �� ������.
    uint32_t len = 0;     //����� ������ �����, ����
};

/*!
 * \brief ��������� ������ � ���� ���������� ������ �������.
 */
struct StatServer {

    StatServer() {
        memset(this, 0, sizeof(*this));
    }

    uint32_t incBytes;  //������� ����
    uint32_t sendBytes; //�������� ����
    uint32_t revPck;    //������ �������
    uint32_t sendPck;   //�������� �������
    uint32_t workTime;  //����� ������ ������� ������
    uint32_t clients;   //���������� ������������ ��������
};


#pragma pack(pop)
#endif // STRUCTS_H