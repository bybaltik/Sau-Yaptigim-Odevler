using Microsoft.EntityFrameworkCore;
using WEB_PROGRAMLAMA_PROJESI_2024.Models;

namespace WEB_PROGRAMLAMA_PROJESI_2024.Data
{
    public class ApplicationDbContext:DbContext
    {
          
        public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options) : base(options)
        {

        }
        public DbSet<Musteri> Musteris { get; set; }

        public DbSet<Rol> Rols { get; set; }

        public DbSet<Salon> Salons { get; set; }
        public DbSet<Islem> Islems { get; set; }
        public DbSet<Calisan> Calisans { get; set; }
        
        public DbSet<Randevu> Randevus { get; set; }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);

            // Randevu - Musteri ilişki (Many-to-One)
            modelBuilder.Entity<Randevu>()
                .HasOne(r => r.Musteri)
                .WithMany()
                .HasForeignKey(r => r.MusteriId)
                .OnDelete(DeleteBehavior.Restrict); // Silmeyi engelle

            // Randevu - Calisan ilişki (Many-to-One)
            modelBuilder.Entity<Randevu>()
                .HasOne(r => r.Calisan)
                .WithMany()
                .HasForeignKey(r => r.CalisanId)
                .OnDelete(DeleteBehavior.Restrict); // Silmeyi engelle

            // Randevu - Islem ilişki (Many-to-One)
            modelBuilder.Entity<Randevu>()
                .HasOne(r => r.Islem)
                .WithMany()
                .HasForeignKey(r => r.IslemId)
                .OnDelete(DeleteBehavior.Restrict); // Silmeyi engelle

            // Calisan - Islem ilişki (Many-to-One)
            modelBuilder.Entity<Calisan>()
                .HasOne(c => c.Islem)
                .WithMany()
                .HasForeignKey(c => c.IslemId)
                .OnDelete(DeleteBehavior.Restrict);

            // Calisan - Rol ilişki (Many-to-One)
            modelBuilder.Entity<Calisan>()
                .HasOne(c => c.Rol)
                .WithMany()
                .HasForeignKey(c => c.RolId)
                .OnDelete(DeleteBehavior.Restrict);

            // Calisan - Salon ilişki (Many-to-One)
            modelBuilder.Entity<Calisan>()
                .HasOne(c => c.Salon)
                .WithMany()
                .HasForeignKey(c => c.SalonId)
                .OnDelete(DeleteBehavior.Restrict);

            // Islem - Salon ilişki (Many-to-One)
            modelBuilder.Entity<Islem>()
                .HasOne(i => i.Salon)
                .WithMany()
                .HasForeignKey(i => i.SalonId)
                .OnDelete(DeleteBehavior.Restrict);
        }




    }


}
