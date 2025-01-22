using System;
using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace WEB_PROGRAMLAMA_PROJESI_2024.Migrations
{
    /// <inheritdoc />
    public partial class InitialCreate : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "Musteris",
                columns: table => new
                {
                    MusteriId = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    MusteriAdi = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    MusteriSifre = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Email = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Telefon = table.Column<string>(type: "nvarchar(max)", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Musteris", x => x.MusteriId);
                });

            migrationBuilder.CreateTable(
                name: "Rols",
                columns: table => new
                {
                    RolId = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    RolAdi = table.Column<string>(type: "nvarchar(max)", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Rols", x => x.RolId);
                });

            migrationBuilder.CreateTable(
                name: "Salons",
                columns: table => new
                {
                    SalonId = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    SalonAdi = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Adres = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    CalismaSaatleri = table.Column<string>(type: "nvarchar(max)", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Salons", x => x.SalonId);
                });

            migrationBuilder.CreateTable(
                name: "Islems",
                columns: table => new
                {
                    IslemId = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    SalonId = table.Column<int>(type: "int", nullable: false),
                    IslemAdi = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Sure = table.Column<int>(type: "int", nullable: false),
                    Ucret = table.Column<int>(type: "int", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Islems", x => x.IslemId);
                    table.ForeignKey(
                        name: "FK_Islems_Salons_SalonId",
                        column: x => x.SalonId,
                        principalTable: "Salons",
                        principalColumn: "SalonId",
                        onDelete: ReferentialAction.Restrict);
                });

            migrationBuilder.CreateTable(
                name: "Calisans",
                columns: table => new
                {
                    CalisanId = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    IslemId = table.Column<int>(type: "int", nullable: false),
                    SalonId = table.Column<int>(type: "int", nullable: false),
                    RolId = table.Column<int>(type: "int", nullable: false),
                    AdSoyad = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    KullaniciAdi = table.Column<string>(type: "nvarchar(50)", maxLength: 50, nullable: false),
                    Sifre = table.Column<string>(type: "nvarchar(100)", maxLength: 100, nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Calisans", x => x.CalisanId);
                    table.ForeignKey(
                        name: "FK_Calisans_Islems_IslemId",
                        column: x => x.IslemId,
                        principalTable: "Islems",
                        principalColumn: "IslemId",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_Calisans_Rols_RolId",
                        column: x => x.RolId,
                        principalTable: "Rols",
                        principalColumn: "RolId",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_Calisans_Salons_SalonId",
                        column: x => x.SalonId,
                        principalTable: "Salons",
                        principalColumn: "SalonId",
                        onDelete: ReferentialAction.Restrict);
                });

            migrationBuilder.CreateTable(
                name: "Randevus",
                columns: table => new
                {
                    RandevuId = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    MusteriId = table.Column<int>(type: "int", nullable: false),
                    CalisanId = table.Column<int>(type: "int", nullable: false),
                    IslemId = table.Column<int>(type: "int", nullable: false),
                    Tarih = table.Column<DateTime>(type: "datetime2", nullable: false),
                    SaatAraligi = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Onay = table.Column<bool>(type: "bit", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Randevus", x => x.RandevuId);
                    table.ForeignKey(
                        name: "FK_Randevus_Calisans_CalisanId",
                        column: x => x.CalisanId,
                        principalTable: "Calisans",
                        principalColumn: "CalisanId",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_Randevus_Islems_IslemId",
                        column: x => x.IslemId,
                        principalTable: "Islems",
                        principalColumn: "IslemId",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_Randevus_Musteris_MusteriId",
                        column: x => x.MusteriId,
                        principalTable: "Musteris",
                        principalColumn: "MusteriId",
                        onDelete: ReferentialAction.Restrict);
                });

            migrationBuilder.CreateIndex(
                name: "IX_Calisans_IslemId",
                table: "Calisans",
                column: "IslemId");

            migrationBuilder.CreateIndex(
                name: "IX_Calisans_RolId",
                table: "Calisans",
                column: "RolId");

            migrationBuilder.CreateIndex(
                name: "IX_Calisans_SalonId",
                table: "Calisans",
                column: "SalonId");

            migrationBuilder.CreateIndex(
                name: "IX_Islems_SalonId",
                table: "Islems",
                column: "SalonId");

            migrationBuilder.CreateIndex(
                name: "IX_Randevus_CalisanId",
                table: "Randevus",
                column: "CalisanId");

            migrationBuilder.CreateIndex(
                name: "IX_Randevus_IslemId",
                table: "Randevus",
                column: "IslemId");

            migrationBuilder.CreateIndex(
                name: "IX_Randevus_MusteriId",
                table: "Randevus",
                column: "MusteriId");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "Randevus");

            migrationBuilder.DropTable(
                name: "Calisans");

            migrationBuilder.DropTable(
                name: "Musteris");

            migrationBuilder.DropTable(
                name: "Islems");

            migrationBuilder.DropTable(
                name: "Rols");

            migrationBuilder.DropTable(
                name: "Salons");
        }
    }
}
