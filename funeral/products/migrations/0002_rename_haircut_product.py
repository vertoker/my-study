# Generated by Django 4.1.5 on 2023-01-09 13:40

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('products', '0001_initial'),
    ]

    operations = [
        migrations.RenameModel(
            old_name='Haircut',
            new_name='Product',
        ),
    ]