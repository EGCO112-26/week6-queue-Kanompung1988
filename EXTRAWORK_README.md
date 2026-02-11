# 🏥 AREAZERO AI CLINIC - Queue Management System

## 📋 Project Description
ระบบจัดการคิวสำหรับคลินิก AREAZERO AI CLINIC ที่ให้บริการซอฟต์แวร์ AI สำหรับการตรวจสุขภาพและระบบวิจัยขั้นสูง

## 🎯 Features (ครบทั้ง 5 ข้อตามที่กำหนด)

### ✅ 1. รับข้อมูลผ่าน ARGC/ARGV
- รับคำสั่งผ่าน command line arguments
- รองรับตัวเลข 1-7 เพื่อดำเนินการต่างๆ

### ✅ 2. ปรับเมนู/Interface สวยงาม
- ใช้ Unicode Box Drawing Characters
- แสดง Header และ Menu ที่สวยงาม
- มี Emoji ประกอบเพื่อความน่าสนใจ
- แสดงคำอธิบายสินค้า/บริการ

### ✅ 3. มีระบบรับเงิน/ทอนเงิน ตอน dequeue
- ระบบรับเงินและคำนวณเงินทอน
- แจ้งเตือนเมื่อจ่ายเงินไม่พอ
- แสดงรายละเอียดการชำระเงินอย่างชัดเจน

### ✅ 4. บอกว่ามีเหลือกี่คนใน queue ตอนปิดร้าน
- แสดงจำนวนลูกค้าที่เหลือในคิว
- แสดงเมื่อเลือก option 7 หรือสิ้นสุดโปรแกรม

### ✅ 5. เคลียร์คิวก่อนจบโปรแกรม
- ล้างข้อมูลลูกค้าที่เหลือในคิว
- แสดงรายละเอียดการล้างข้อมูล
- ป้องกัน memory leak

## 🛠️ Services (สินค้า/บริการ)

| รหัส | ชื่อบริการ | คำอธิบาย | ราคา (฿) |
|------|-----------|---------|---------|
| 1 | **Smart Liva** | AI Software for Liver Detection<br/>ซอฟต์แวร์ AI สำหรับตรวจตับ | 250 |
| 2 | **Cardiacz** | AI Software for Heart Disease Detection<br/>ซอฟต์แวร์ AI สำหรับตรวจโรคหัวใจ | 200 |
| 3 | **Ninja** | Multi-Agent Deep Research & Generate Slides<br/>ระบบวิจัยขั้นสูงและสร้างสไลด์อัตโนมัติ | 180 |
| 4 | **Nong Sai** | Health Monitoring System<br/>ระบบติดตามสุขภาพ | 150 |
| 5 | **Nong Picha** | General Health Checkup<br/>การตรวจสุขภาพทั่วไป | 100 |
| 6 | **Serve** | Serve Next Customer<br/>เรียกลูกค้าคนถัดไป | - |
| 7 | **Close** | Close Clinic<br/>ปิดคลินิก | - |

## 🚀 How to Compile

```bash
gcc extrawork.c -o areazero
```

## 📝 How to Use

### วิธีที่ 1: รันโปรแกรมพร้อมคำสั่ง
```bash
./areazero 1 2 3 6 6 7
```

### วิธีที่ 2: รันโปรแกรมพร้อมป้อนเงิน
```bash
echo -e "300\n500" | ./areazero 1 2 6 6 7
```

### ตัวอย่างการใช้งาน

#### ตัวอย่างที่ 1: สั่งซื้อและบริการลูกค้า
```bash
echo -e "300\n200" | ./areazero 1 2 6 6 7
```
- เพิ่ม Smart Liva (Customer #1)
- เพิ่ม Cardiacz (Customer #2)
- บริการ Customer #1 (จ่าย 300 ฿ สำหรับ Smart Liva 250 ฿, ทอน 50 ฿)
- บริการ Customer #2 (จ่าย 200 ฿ สำหรับ Cardiacz 200 ฿, พอดี)
- ปิดคลินิก

#### ตัวอย่างที่ 2: มีลูกค้าค้างในคิว
```bash
./areazero 1 2 3 4 5 6 7
```
- เพิ่มลูกค้า 5 คน
- บริการ 1 คน
- ปิดคลินิก (เหลือลูกค้า 4 คนในคิว)
- ระบบจะเคลียร์ลูกค้าที่เหลืออัตโนมัติ

## 🎨 Interface Design

โปรแกรมนี้มี interface ที่สวยงามประกอบด้วย:
- 🏥 Header พร้อม logo คลินิก
- 📋 Menu แสดงรายการบริการทั้งหมด
- 💰 Payment section สำหรับการชำระเงิน
- 🔔 Notification เมื่อบริการลูกค้า
- 🧹 Queue clearing summary ก่อนปิดโปรแกรม

## 🏗️ Data Structures

### Order (Node)
```c
typedef struct node {
   struct node* next;
   int order_number;
   int customer_number;
   char product[100];
   char description[200];
   int price;
} Order;
```

### OrderQueue
```c
typedef struct {
   Order *head, *tail;
   int size;
} OrderQueue;
```

## 🔧 Functions

- `printHeader()` - แสดง header ของโปรแกรม
- `printMenu()` - แสดงเมนูบริการ
- `createOrder()` - สร้าง order ใหม่
- `enqueue()` - เพิ่มลูกค้าเข้าคิว
- `dequeue()` - ดึงลูกค้าออกจากคิว
- `processPayment()` - จัดการระบบชำระเงิน

## 📊 Example Output

```
╔════════════════════════════════════════════════════════════════════╗
║                    🏥 AREAZERO AI CLINIC 🏥                        ║
║              Advanced Medical AI Solutions Provider               ║
╚════════════════════════════════════════════════════════════════════╝

┌────────────────────────────────────────────────────────────────────┐
│                          📋 MENU 📋                                │
├────────────────────────────────────────────────────────────────────┤
│ 1. Smart Liva     - AI Software for Liver Detection    [250 ฿]   │
│ 2. Cardiacz       - AI Software for Heart Disease      [200 ฿]   │
│ 3. Ninja          - Multi-Agent Deep Research & Slides [180 ฿]   │
│ 4. Nong Sai       - Health Monitoring System           [150 ฿]   │
│ 5. Nong Picha     - General Health Checkup             [100 ฿]   │
│ 6. 💳 Serve Next Customer                                         │
│ 7. 🚪 Close Clinic                                                │
└────────────────────────────────────────────────────────────────────┘

✅ My order is 1
📝 Customer #1 - Smart Liva added to queue
...
```

## 👨‍💻 Author
- **Course**: EGCO112-26
- **Assignment**: Week 6 - Queue (Extra Work)
- **Repository**: week6-queue-Kanompung1988

## 📄 License
This project is created for educational purposes.

---
**Note**: โปรแกรมนี้ใช้ Queue (FIFO) ในการจัดการลูกค้า เพื่อให้การบริการเป็นไปตามลำดับที่มาก่อนได้บริการก่อน
