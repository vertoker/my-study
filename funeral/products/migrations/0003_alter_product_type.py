# Generated by Django 4.1.5 on 2023-01-09 14:08

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('products', '0002_rename_haircut_product'),
    ]

    operations = [
        migrations.AlterField(
            model_name='product',
            name='type',
            field=models.CharField(choices=[('CF', 'Гробы'), ('WR', 'Венки'), ('CR', 'Кресты на могилу'), ('MN', 'Памятники на могилу'), ('TX', 'Текстиль'), ('N', 'None')], default='N', max_length=2),
        ),
    ]
