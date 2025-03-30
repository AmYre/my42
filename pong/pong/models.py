from django.db import models

# Create your models here.
class User(models.Model):
	username = models.CharField(max_length=50)
	password = models.CharField(max_length=50)
	email = models.CharField(max_length=50)
	created_at = models.DateTimeField(auto_now_add=True)

class GameStats(models.Model):
    user = models.CharField(max_length=100)
    score = models.IntegerField(default=0)
    user2 = models.CharField(max_length=100)
    score2 = models.IntegerField(default=0)
    user3 = models.CharField(max_length=100)
    score3 = models.IntegerField(default=0)
    mode = models.CharField(max_length=50)
    options = models.JSONField()
    created_at = models.DateTimeField(auto_now_add=True)

    class Meta:
        ordering = ['-created_at']